#!/system/bin/sh
<<<<<<< HEAD
{

	until [ "$(getprop sys.boot_completed)" = 1 ]; do sleep 1; done
	until [ -d "/sdcard/Android" ]; do sleep 1; done

	MODDIR=${0%/*}
	. "$MODDIR/config"

	rm "/data/adb/rvhc/${MODDIR##*/}.apk"
	rmdir "/data/adb/rvhc"
	rm "/data/adb/post-fs-data.d/$PKG_NAME-uninstall.sh"
} &
=======

MODDIR=${0%/*}
. "$MODDIR/config"

rm -f "/data/adb/rvhc/${MODDIR##*/}.apk"
rmdir "/data/adb/rvhc"

rm -f "/data/adb/post-fs-data.d/$PKG_NAME-uninstall.sh"
>>>>>>> 9eb51025e17f37bd2b3b6334366906f2e353d969
