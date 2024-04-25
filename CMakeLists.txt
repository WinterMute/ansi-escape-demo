cmake_minimum_required(VERSION 3.13)

project(ansi-escape-demo LANGUAGES C VERSION 1.0.0)

add_executable(${PROJECT_NAME})

target_sources(${PROJECT_NAME} PRIVATE
	source/main.c
)

dkp_target_generate_symbol_list(${PROJECT_NAME})

target_compile_options(${PROJECT_NAME} PRIVATE -g -O2 -Wall)

target_include_directories(${PROJECT_NAME} PRIVATE
  include
)

if(NINTENDO_3DS)
  target_include_directories(${PROJECT_NAME} PRIVATE
    include/platform/3ds
  )

  target_sources(${PROJECT_NAME} PRIVATE
    source/3ds/platform.c
  )

  ctr_generate_smdh(${PROJECT_NAME}.smdh
    NAME "${PROJECT_NAME}"
    DESCRIPTION "v${PROJECT_VERSION}"
    AUTHOR "(c) 2024 Dave Murphy"
  )

  ctr_create_3dsx(${PROJECT_NAME}
    SMDH ${PROJECT_NAME}.smdh
  )
endif()

if(NINTENDO_WII)
  target_include_directories(${PROJECT_NAME} PRIVATE
    include/platform/wii
  )
endif()

if(NINTENDO_GAMECUBE)
  target_include_directories(${PROJECT_NAME} PRIVATE
    include/platform/gamecube
  )
endif()

if(NINTENDO_WII OR NINTENDO_GAMECUBE)

  target_sources(${PROJECT_NAME} PRIVATE
    source/ogc/platform.c
  )

  ogc_create_dol(test)

endif()

if(NINTENDO_SWITCH)
  target_include_directories(${PROJECT_NAME} PRIVATE
    include/platform/switch
  )

  target_sources(${PROJECT_NAME} PRIVATE
    source/switch/platform.c
  )

    nx_generate_nacp(${PROJECT_NAME}.nacp
      NAME "${PROJECT_NAME}"
      AUTHOR "(c) 2024 Dave Murphy"
      VERSION ${PROJECT_VERSION}
    )

    nx_create_nro(${PROJECT_NAME}
      NACP ${PROJECT_NAME}.nacp
    )
endif()
