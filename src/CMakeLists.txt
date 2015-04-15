set(kcm_lookandfeel_SRCS
  kcm.cpp
)

set(klauncher_xml ${KINIT_DBUS_INTERFACES_DIR}/kf5_org.kde.KLauncher.xml)
qt5_add_dbus_interface(kcm_lookandfeel_SRCS ${klauncher_xml} klauncher_iface)

add_library(kcm_lookandfeel MODULE ${kcm_lookandfeel_SRCS})

target_link_libraries(kcm_lookandfeel
  KF5::CoreAddons
  KF5::KCMUtils
  KF5::I18n
  KF5::Plasma
  KF5::KDELibs4Support
  KF5::Declarative

  Qt5::DBus
)

kcoreaddons_desktop_to_json(kcm_lookandfeel "kcm_lookandfeel.desktop")

#this desktop file is installed only for retrocompatibility with sycoca
install(FILES kcm_lookandfeel.desktop DESTINATION ${SERVICES_INSTALL_DIR})
install(TARGETS kcm_lookandfeel DESTINATION ${PLUGIN_INSTALL_DIR}/kcms)

kpackage_install_package(package kcm_lookandfeel kcms)
