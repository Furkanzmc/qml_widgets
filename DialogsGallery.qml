import Qml.Widgets
import Qml.Widgets.Dialogs

Widget {
    id: root
    height: 200
    visible: true
    windowTitle: "Dialogs Gallery"

    VBoxLayout {
        PushButton {
            text: "Font Dialog"
            onClicked: {
                fontDlg.open()
            }
        }

        PushButton {
            text: "Color Dialog"
            toolTip: "Show color dialog using QColorDialog"
            onClicked: {
                colorDlg.open()
            }
        }

        PushButton {
            text: "Message Box"
            onClicked: {
                msgBox.open()
            }
        }

        PushButton {
            text: "File Dialog"
            onClicked: {
                fileDlg.open()
            }
        }

        PushButton {
            text: "Error Message"
            onClicked: {
                errMsg.showMessage("Here's an error message.", "Here's a type.")
            }
        }

        PushButton {
            text: "Text Input Dialog"
            onClicked: {
                textInputDlg.open()
            }
        }

        PushButton {
            text: "Int Input Dialog"
            onClicked: {
                intInputDlg.open()
            }
        }

        PushButton {
            text: "Double Input Dialog"
            onClicked: {
                doubleInputDlg.open()
            }
        }
    }

    ErrorMessage {
        id: errMsg
    }

    MessageBox {
        id: msgBox
        text: "Are you sure you want to view the message box?"
        detailedText: "This message box is created from QML."
        standardButtons: MessageBox.OK | MessageBox.Close
    }

    ColorDialog {
        id: colorDlg
    }

    FontDialog {
        id: fontDlg
    }

    FileDialog {
        id: fileDlg
    }

    InputDialog {
        id: textInputDlg
        windowTitle: "User Name"
        inputMode: InputDialog.TextInput
        onTextValueChanged: {
            console.log("[DialogsGallery.qml::84::onTextValueChanged]", textValue)
        }
    }

    InputDialog {
        id: intInputDlg
        windowTitle: "User Age"
        inputMode: InputDialog.IntInput
        onIntValueChanged: {
            console.log("[DialogsGallery.qml::92::onIntValueChanged]", intValue)
        }
    }

    InputDialog {
        id: doubleInputDlg
        windowTitle: "Ratio"
        inputMode: InputDialog.DoubleInput
        onDoubleValueChanged: {
            console.log("[DialogsGallery.qml::115::onDoubleValueChanged]", doubleValue)
        }
    }
}
