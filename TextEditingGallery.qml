import Qml.Widgets

Widget {
    id: root
    height: 200
    visible: true
    windowTitle: "Text Editing Gallery"

    VBoxLayout {
        HBoxLayout {
            Label {
                text: "First Name"
            }

            Spacer {
            }

            LineEdit {

            }
        }

        HBoxLayout {
            Label {
                text: "Last Name"
            }

            LineEdit {

            }
        }

        HBoxLayout {
            Label {
                text: "Email"
            }

            LineEdit {

            }
        }

        HBoxLayout {
            Label {
                text: "Plain Text Field"
            }

            PlainTextEdit {

            }
        }

        HBoxLayout {
            Label {
                text: "About Me"
            }

            TextEdit {

            }
        }
    }
}
