import Qml.Widgets

Widget {
    id: root
    height: 200
    visible: true
    windowTitle: "Text Editing Gallery"

    FormLayout {
        labelAlignment: Qt.AlignLeft

        LineEdit {
            Layout.label: "First Name"
        }

        LineEdit {
            Layout.label: "Last Name"
        }

        LineEdit {
            Layout.label:  "Email"

        }

        PlainTextEdit {
            Layout.label: "Plain Text Field"
        }

        TextEdit {
            Layout.label: "About Me"
        }

        KeySequenceEdit {
            Layout.label: "Shortcut"
        }
    }
}
