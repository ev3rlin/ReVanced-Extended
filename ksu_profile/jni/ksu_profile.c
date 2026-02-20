#include <errno.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
<<<<<<< HEAD
#include <sys/prctl.h>
#include <unistd.h>

#define KSU_MAX_PACKAGE_NAME 256
#define KSU_MAX_GROUPS 32
#define KSU_SELINUX_DOMAIN 64
#define KSU_APP_PROFILE_VER 2
=======
#include <sys/ioctl.h>
#include <sys/syscall.h>
#include <unistd.h>

#define KSU_INSTALL_MAGIC1 0xDEADBEEF
#define KSU_INSTALL_MAGIC2 0xCAFEBABE

#define KSU_APP_PROFILE_VER 2
#define KSU_MAX_PACKAGE_NAME 256
#define KSU_MAX_GROUPS 32
#define KSU_SELINUX_DOMAIN 64

#define KSU_IOCTL_MAGIC 'K'
#define KSU_IOCTL_UID_SHOULD_UMOUNT _IOC(_IOC_READ | _IOC_WRITE, KSU_IOCTL_MAGIC, 9, 0)
#define KSU_IOCTL_GET_MANAGER_APPID _IOC(_IOC_READ, KSU_IOCTL_MAGIC, 10, 0)
#define KSU_IOCTL_GET_APP_PROFILE _IOC(_IOC_READ | _IOC_WRITE, KSU_IOCTL_MAGIC, 11, 0)
#define KSU_IOCTL_SET_APP_PROFILE _IOC(_IOC_WRITE, KSU_IOCTL_MAGIC, 12, 0)
>>>>>>> 6712933177658500993ce6594364903d57e1c14f

struct root_profile {
    int32_t uid;
    int32_t gid;
<<<<<<< HEAD

=======
>>>>>>> 6712933177658500993ce6594364903d57e1c14f
    int32_t groups_count;
    int32_t groups[KSU_MAX_GROUPS];

    struct {
        uint64_t effective;
        uint64_t permitted;
        uint64_t inheritable;
    } capabilities;

    char selinux_domain[KSU_SELINUX_DOMAIN];
<<<<<<< HEAD

=======
>>>>>>> 6712933177658500993ce6594364903d57e1c14f
    int32_t namespaces;
};

struct non_root_profile {
    bool umount_modules;
};

struct app_profile {
    uint32_t version;
<<<<<<< HEAD

    char key[KSU_MAX_PACKAGE_NAME];
    int32_t current_uid;
    bool allow_su;

=======
    char key[KSU_MAX_PACKAGE_NAME];
    int32_t current_uid;
    bool allow_su;
>>>>>>> 6712933177658500993ce6594364903d57e1c14f
    union {
        struct {
            bool use_default;
            char template_name[KSU_MAX_PACKAGE_NAME];
<<<<<<< HEAD

            struct root_profile profile;
        } rp_config;

        struct {
            bool use_default;

=======
            struct root_profile profile;
        } rp_config;
        struct {
            bool use_default;
>>>>>>> 6712933177658500993ce6594364903d57e1c14f
            struct non_root_profile profile;
        } nrp_config;
    };
};

<<<<<<< HEAD
#define CMD_GET_APP_PROFILE 10
#define CMD_SET_APP_PROFILE 11
#define CMD_IS_UID_GRANTED_ROOT 12
#define CMD_IS_UID_SHOULD_UMOUNT 13
#define CMD_GET_MANAGER_UID 16

#define KERNEL_SU_OPTION 0xDEADBEEF

static bool ksuctl(int cmd, void* arg1, void* arg2) {
    uint32_t result = 0;
    prctl(KERNEL_SU_OPTION, cmd, arg1, arg2, &result);
    return result == KERNEL_SU_OPTION;
}

#define REPORT_ERR(e)                                                                  \
    ({                                                                                 \
        bool ok = (e);                                                                 \
        if (!ok) {                                                                     \
            fprintf(stderr, "%s:%d ERROR: %s\n", __FILE__, __LINE__, strerror(errno)); \
        }                                                                              \
        ok;                                                                            \
    })

int main(int argc, char* argv[]) {
    if (argc <= 2) {
        fprintf(stderr, "Usage: %s <uid> <pkg name>\n", argv[0]);
        return 1;
    }
    long uid = atol(argv[1]);
    bool should_umount = false;
    if (!REPORT_ERR(ksuctl(CMD_IS_UID_SHOULD_UMOUNT, (void*)uid, &should_umount))) return 1;
    if (!should_umount) return 0;

    long manager_uid = 0;
    if (!REPORT_ERR(ksuctl(CMD_GET_MANAGER_UID, &manager_uid, NULL))) return 1;
    if (setuid(manager_uid) != 0) {
        fprintf(stderr, "ERROR setuid: %s\n", strerror(errno));
        return 1;
    }

    struct app_profile profile = {0};
    profile.current_uid = uid;
    if (!ksuctl(CMD_GET_APP_PROFILE, &profile, NULL)) {
        printf("Create profile for %s\n", argv[2]);
        profile.version = KSU_APP_PROFILE_VER;
        strcpy(profile.key, argv[2]);
=======
struct ksu_uid_should_umount_cmd {
    uint32_t uid;
    uint8_t should_umount;
};

struct ksu_get_manager_appid_cmd {
    uint32_t appid;
};

static int _fd = -1;
#define ksuctl(op, ...) (ioctl(_fd, op, __VA_ARGS__) >= 0)

#define REPORT_ERR() fprintf(stderr, "%s:%d ERROR: %s\n", __FILE__, __LINE__, strerror(errno));

int main(int argc, char* argv[]) {
    if (argc <= 2) {
        fprintf(stderr,
                "ksu_profile (github.com/j-hc)\n"
                "Disables \"Unmount modules\" for given package\n"
                "    Usage: %s <pkg uid> <pkg name>\n",
                argv[0]);
        return 1;
    }

    syscall(SYS_reboot, KSU_INSTALL_MAGIC1, KSU_INSTALL_MAGIC2, 0, &_fd);
    if (_fd == -1) {
        REPORT_ERR();
        return 1;
    }
    long uid = atol(argv[1]);

    struct ksu_uid_should_umount_cmd umount_cmd = {0};
    if (!ksuctl(KSU_IOCTL_UID_SHOULD_UMOUNT, &umount_cmd)) {
        REPORT_ERR();
        return 1;
    }
    if (!umount_cmd.should_umount) return 0;

    struct ksu_get_manager_appid_cmd appid_cmd = {0};
    if (!ksuctl(KSU_IOCTL_GET_MANAGER_APPID, &appid_cmd)) {
        REPORT_ERR();
        return 1;
    }

    if (setuid(appid_cmd.appid) != 0) {
        REPORT_ERR();
        return 1;
    }
    struct app_profile profile = {0};
    profile.current_uid = uid;
    if (!ksuctl(KSU_IOCTL_GET_APP_PROFILE, &profile)) {
        printf("Create profile for %s\n", argv[2]);
        profile.version = KSU_APP_PROFILE_VER;
        strncpy(profile.key, argv[2], sizeof(profile.key) / sizeof(profile.key[0]));
>>>>>>> 6712933177658500993ce6594364903d57e1c14f
    }

    profile.nrp_config.use_default = false;
    profile.nrp_config.profile.umount_modules = false;
<<<<<<< HEAD
    if (!REPORT_ERR(ksuctl(CMD_SET_APP_PROFILE, &profile, NULL))) return 1;

    printf("Success\n");
=======

    if (!ksuctl(KSU_IOCTL_SET_APP_PROFILE, &profile)) {
        REPORT_ERR();
        return 1;
    }

>>>>>>> 6712933177658500993ce6594364903d57e1c14f
    return 0;
}
