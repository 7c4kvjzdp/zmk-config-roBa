# roBa zmk-config をモジュールとして読み込んだときの追加ソース
if(CONFIG_LAYOUT_SHIFT AND ((NOT CONFIG_ZMK_SPLIT) OR CONFIG_ZMK_SPLIT_ROLE_CENTRAL))
  target_sources(app PRIVATE ${CMAKE_CURRENT_LIST_DIR}/src/jis_default_on.c)
endif()
