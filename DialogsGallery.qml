import Qml.Widgets
import Qml.Widgets.Dialogs

Widget {
    id: root
    height: 200
    visible: true
    windowTitle: "Buttons Gallery"

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
}
