cmake_minimum_required(VERSION 3.18)

set(QtnProperty_SRC
    PropertyBase.cpp
    Property.cpp
    PropertySet.cpp
    Enum.cpp
    QObjectPropertySet.cpp
    Core/PropertyBool.cpp
    Core/PropertyInt.cpp
    Core/PropertyUInt.cpp
    Core/PropertyDouble.cpp
    Core/PropertyFloat.cpp
    Core/PropertyQString.cpp
    Core/PropertyQRect.cpp
    Core/PropertyEnum.cpp
    Core/PropertyEnumFlags.cpp
    Core/PropertyQSize.cpp
    Core/PropertyQPoint.cpp
    GUI/PropertyQColor.cpp
    GUI/PropertyQFont.cpp
    GUI/PropertyQBrush.cpp
    GUI/PropertyQPen.cpp
    GUI/PropertyButton.cpp
    PropertyWidget.cpp
    PropertyView.cpp
    Utils/InplaceEditing.cpp
    Delegates/PropertyDelegate.cpp
    Delegates/PropertyDelegateAux.cpp
    Delegates/PropertyDelegateFactory.cpp
    Delegates/Core/PropertyDelegateBool.cpp
    Delegates/Core/PropertyDelegateInt.cpp
    Delegates/Core/PropertyDelegateUInt.cpp
    Delegates/Core/PropertyDelegateQString.cpp
    Delegates/Core/PropertyDelegateDouble.cpp
    Delegates/Core/PropertyDelegateFloat.cpp
    Delegates/Core/PropertyDelegateEnum.cpp
    Delegates/Core/PropertyDelegateQRect.cpp
    Delegates/Core/PropertyDelegateQRectF.cpp
    Delegates/Core/PropertyDelegateEnumFlags.cpp
    Delegates/Core/PropertyDelegateQSize.cpp
    Delegates/Core/PropertyDelegateQSizeF.cpp
    Delegates/Core/PropertyDelegateQPoint.cpp
    Delegates/Core/PropertyDelegateQPointF.cpp
    Delegates/GUI/PropertyDelegateQColor.cpp
    Delegates/GUI/PropertyDelegateQBrush.cpp
    Delegates/GUI/PropertyDelegateQPen.cpp
    Delegates/GUI/PropertyDelegateQFont.cpp
    Delegates/GUI/PropertyDelegateButton.cpp
    Delegates/Utils/PropertyEditorHandler.cpp
    Delegates/Utils/PropertyEditorAux.cpp
    Delegates/Utils/PropertyDelegateMisc.cpp
    Delegates/Utils/PropertyDelegatePropertySet.cpp
    Delegates/Utils/PropertyDelegateSliderBox.cpp
    Delegates/Utils/PropertyDelegateGeoCoord.cpp
    Delegates/Utils/PropertyDelegateGeoPoint.cpp
    Utils/AccessibilityProxy.cpp
    Utils/DoubleSpinBox.cpp
    Utils/MultilineTextDialog.cpp
    PropertyInt64.cpp
    PropertyUInt64.cpp
    Core/PropertyQRectF.cpp
    Core/PropertyQPointF.cpp
    Core/PropertyQSizeF.cpp
    PropertyWidgetEx.cpp
    CustomPropertyEditorDialog.cpp
    CustomPropertyOptionsDialog.cpp
    VarProperty.cpp
    PropertyQVariant.cpp
    CustomPropertyWidget.cpp
    QObjectPropertyWidget.cpp
    MultiProperty.cpp
    PropertyConnector.cpp
    Utils/QtnConnections.cpp
    Utils/QtnInt64SpinBox.cpp
    Auxiliary/PropertyDelegateInfo.cpp
    PropertyQKeySequence.cpp
    PropertyDelegateMetaEnum.cpp
    Install.cpp
    Utils/QtnCompleterLineEdit.cpp
    Utils/QtnCompleterItemDelegate.cpp
    GUI/PropertyQVector3D.cpp
    Delegates/GUI/PropertyDelegateQVector3D.cpp
)

set(QtnProperty_HEADER
    PropertyBase.h
    Property.h
    PropertySet.h
    Enum.h
    QObjectPropertySet.h
    PropertyCore.h
    PropertyGUI.h
    Auxiliary/PropertyTemplates.h
    Auxiliary/PropertyMacro.h
    Auxiliary/PropertyAux.h
    Auxiliary/PropertyDelegateInfo.h
    Core/PropertyBool.h
    Core/PropertyInt.h
    Core/PropertyUInt.h
    Core/PropertyDouble.h
    Core/PropertyFloat.h
    Core/PropertyQString.h
    Core/PropertyQRect.h
    Core/PropertyEnum.h
    Core/PropertyEnumFlags.h
    Core/PropertyQSize.h
    Core/PropertyQPoint.h
    GUI/PropertyQColor.h
    GUI/PropertyQFont.h
    GUI/PropertyQBrush.h
    GUI/PropertyQPen.h
    GUI/PropertyButton.h
    PropertyWidget.h
    PropertyView.h
    Utils/InplaceEditing.h
    Delegates/PropertyDelegate.h
    Delegates/PropertyDelegateAux.h
    Delegates/PropertyDelegateFactory.h
    Delegates/Core/PropertyDelegateBool.h
    Delegates/Core/PropertyDelegateInt.h
    Delegates/Core/PropertyDelegateUInt.h
    Delegates/Core/PropertyDelegateQString.h
    Delegates/Core/PropertyDelegateDouble.h
    Delegates/Core/PropertyDelegateFloat.h
    Delegates/Core/PropertyDelegateEnum.h
    Delegates/Core/PropertyDelegateQRect.h
    Delegates/Core/PropertyDelegateQRectF.h
    Delegates/Core/PropertyDelegateEnumFlags.h
    Delegates/Core/PropertyDelegateQSize.h
    Delegates/Core/PropertyDelegateQSizeF.h
    Delegates/Core/PropertyDelegateQPoint.h
    Delegates/Core/PropertyDelegateQPointF.h
    Delegates/GUI/PropertyDelegateQColor.h
    Delegates/GUI/PropertyDelegateQFont.h
    Delegates/GUI/PropertyDelegateQBrush.h
    Delegates/GUI/PropertyDelegateQPen.h
    Delegates/GUI/PropertyDelegateButton.h
    Delegates/Utils/PropertyEditorHandler.h
    Delegates/Utils/PropertyEditorAux.h
    Delegates/Utils/PropertyDelegateMisc.h
    Delegates/Utils/PropertyDelegatePropertySet.h
    Delegates/Utils/PropertyDelegateSliderBox.h
    Delegates/Utils/PropertyDelegateGeoCoord.h
    Delegates/Utils/PropertyDelegateGeoPoint.h
    Utils/AccessibilityProxy.h
    Utils/DoubleSpinBox.h
    Utils/MultilineTextDialog.h
    PropertyInt64.h
    PropertyUInt64.h
    Core/PropertyQRectF.h
    Core/PropertyQPointF.h
    Core/PropertyQSizeF.h
    PropertyWidgetEx.h
    CustomPropertyEditorDialog.h
    CustomPropertyOptionsDialog.h
    VarProperty.h
    PropertyQVariant.h
    CustomPropertyWidget.h
    QObjectPropertyWidget.h
    IQtnPropertyStateProvider.h
    MultiProperty.h
    StructPropertyBase.h
    PropertyConnector.h
    Utils/QtnConnections.h
    Utils/QtnInt64SpinBox.h
    PropertyDelegateAttrs.h
    PropertyQKeySequence.h
    PropertyDelegateMetaEnum.h
    Install.h
    Config.h
    FunctionalHelpers.h
    Utils/QtnCompleterLineEdit.h
    Utils/QtnCompleterItemDelegate.h
    GUI/PropertyQVector3D.h
    Delegates/GUI/PropertyDelegateQVector3D.h
)

qt_add_translation(QtnProperty_QM Translations/en.ts Translations/ru.ts)
qt_add_resources(QtnProperty_RC QtnProperty.qrc)
qt_wrap_ui(QtnProperty_UI_HEADER
    CustomPropertyEditorDialog.ui
    CustomPropertyOptionsDialog.ui
    Utils/MultilineTextDialog.ui
)

add_library(QtnProperty SHARED ${QtnProperty_SRC} ${QtnProperty_HEADER} ${QtnProperty_QM} ${QtnProperty_RC} ${QtnProperty_UI_HEADER})

target_compile_definitions(QtnProperty PRIVATE QTN_DYNAMIC_LIBRARY QTN_DYNAMIC_IMPORT)

target_link_libraries(QtnProperty PRIVATE Qt::Core Qt::Widgets)
target_include_directories(QtnProperty PUBLIC $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}> $<INSTALL_INTERFACE:include>)
target_include_directories(QtnProperty PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(QtnProperty PRIVATE ${CMAKE_CURRENT_BINARY_DIR})

# install

install(TARGETS QtnProperty
    EXPORT QtnProperty-targets
    PUBLIC_HEADER DESTINATION include
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib
    RUNTIME DESTINATION bin)

install(EXPORT QtnProperty-targets
    NAMESPACE QtnProperty::
    FILE QtnPropertyConfig.cmake
    DESTINATION lib/cmake/QtnProperty)

install(DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/" # source directory
        DESTINATION "include/QtnProperty" # target directory
        FILES_MATCHING # install only matched files
        PATTERN "*.h" # select header files
        PATTERN "Translations*" EXCLUDE
)

