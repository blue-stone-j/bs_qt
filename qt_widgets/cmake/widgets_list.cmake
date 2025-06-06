file(GLOB WIDGETS_LIST "${CMAKE_CURRENT_SOURCE_DIR}/widgets/*")

foreach(WIDGET ${WIDGETS_LIST})
  if(IS_DIRECTORY ${WIDGET})
    file(RELATIVE_PATH REL_PATH "${CMAKE_CURRENT_SOURCE_DIR}/widgets" "${WIDGET}")
    list(APPEND WIDGETs_NAME ${REL_PATH})
  endif()
endforeach()