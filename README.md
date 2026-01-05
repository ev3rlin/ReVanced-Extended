<<<<<<< HEAD
<div align="center">
  <img src="assets/logo.png" width="200" alt="ReVanced Extended Logo by @ev3rlin">

  # ReVanced Extended Magisk Module (mod by [@ev3rlin](https://github.com/ev3rlin))

  [![Telegram](https://img.shields.io/badge/Telegram-2CA5E0?style=for-the-badge&logo=telegram&logoColor=white)](https://t.me/ev3rlin_rvx)

  [![License](https://img.shields.io/github/license/ev3rlin/ReVanced-Extended)](https://github.com/ev3rlin/ReVanced-Extended?tab=GPL-3.0-1-ov-file#readme)
  [![CI](https://github.com/ev3rlin/ReVanced-Extended/actions/workflows/ci.yml/badge.svg?event=schedule)](https://github.com/ev3rlin/ReVanced-Extended/actions/workflows/ci.yml)

  [![Release date](https://img.shields.io/github/release-date/ev3rlin/ReVanced-Extended)](https://github.com/ev3rlin/ReVanced-Extended/releases)
  [![Release version](https://img.shields.io/github/v/release/ev3rlin/ReVanced-Extended?display_name=release)](https://github.com/ev3rlin/ReVanced-Extended/releases/latest)
</div>

---

## 📌 Patches List

| Patch / Application | YouTube RVX | YouTube Music RVX |
|----------------------|-------------|-------------------|
| Included patches | • Visual preferences icons for YouTube<br>• Return YouTube Username | • Visual preferences icons for YouTube Music<br>• Return YouTube Username<br>• Disable music video in album |
| Excluded patches | • Custom header for YouTube | • Custom header for YouTube Music |
| App name | YouTube RVX | YT Music RVX |
| App icon | [Vanced Black](https://github.com/anddea/revanced-patches/wiki/Icons) | [Vanced Black](https://github.com/anddea/revanced-patches/wiki/Icons) |
| Light Theme Background Color | #FFF9F9F9 | - |


## 🚀 Features

  * Updated automatically with the latest supported versions of apps and [anddea patches (stable version)](https://github.com/anddea/revanced-patches)
  * Optimize APKs and modules for size
  * Fully open-source and free to use
  * Modules:
    - recompile invalidated odex for faster usage
    - receive updates from Magisk app
    - do not break safetynet or trigger root detections
    - handle installation of the correct version of the stock app and all that
    - support Magisk and KernelSU

## 📝 Notes

  * <ins>Root</ins> versions: use [zygisk-detach](https://github.com/j-hc/zygisk-detach) to detach YouTube and YT Music from Play Store if you are using magisk modules
  * <ins>Non-root</ins> versions: require [MicroG](https://github.com/ReVanced/GmsCore) to work

## 🙏 Credits

  [j-hc](https://github.com/j-hc) for [zygisk-detach](https://github.com/j-hc/zygisk-detach) and the [ReVanced apps builder](https://github.com/j-hc/revanced-magisk-module) and some more technical stuff

  [ReVanced Team](https://github.com/revanced) for [MicroG](https://github.com/ReVanced/GmsCore)

  [anddea](https://github.com/anddea) for [revanced-extended patches](https://github.com/anddea/revanced-patches)
=======
# ReVanced Magisk Module
[![Telegram](https://img.shields.io/badge/Telegram-2CA5E0?style=for-the-badge&logo=telegram&logoColor=white)](https://t.me/rvc_magisk)
[![CI](https://github.com/j-hc/revanced-magisk-module/actions/workflows/ci.yml/badge.svg?event=schedule)](https://github.com/j-hc/revanced-magisk-module/actions/workflows/ci.yml)

Extensive ReVanced builder  

Get the [latest CI release](https://github.com/j-hc/revanced-magisk-module/releases).

Use [**zygisk-detach**](https://github.com/j-hc/zygisk-detach) to detach YouTube and YT Music from Play Store if you are using magisk modules. 

<details><summary><big>Features</big></summary>
<ul>
 <li>Support all present and future ReVanced and <a href="https://github.com/inotia00/revanced-patches">ReVanced Extended</a> apps</li>
 <li> Can build Magisk modules and non-root APKs</li>
 <li> Updated daily with the latest versions of apps and patches</li>
 <li> Optimize APKs and modules for size</li>
 <li> Modules</li>
    <ul>
     <li> recompile invalidated odex for faster usage</li>
     <li> receive updates from Magisk app</li>
     <li> do not break safetynet or trigger root detections</li>
     <li> handle installation of the correct version of the stock app and all that</li>
     <li> support Magisk and KernelSU</li>
    </ul>
</ul>
Note that the <a href="../../actions/workflows/ci.yml">CI workflow</a> is scheduled to build the modules and APKs everyday using GitHub Actions if there is a change in ReVanced patches. You may want to disable it.
</details>

## To include/exclude patches or patch other apps

 * Star the repo :eyes:
 * Use the repo as a [template](https://github.com/new?template_name=revanced-magisk-module&template_owner=j-hc)
 * Customize [`config.toml`](./config.toml) using [rvmm-config-gen](https://j-hc.github.io/rvmm-config-gen/)
 * Run the build [workflow](../../actions/workflows/build.yml)
 * Grab your modules and APKs from [releases](../../releases)

also see here [`CONFIG.md`](./CONFIG.md)

## Building Locally
### On Termux
```console
bash <(curl -sSf https://raw.githubusercontent.com/j-hc/revanced-magisk-module/main/build-termux.sh)
```

### On Desktop
```console
$ git clone https://github.com/j-hc/revanced-magisk-module
$ cd revanced-magisk-module
$ ./build.sh
```
>>>>>>> e42b4c7764bdb69ea640fd0da93401398028cea8
