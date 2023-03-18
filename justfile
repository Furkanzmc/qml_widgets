qt_dir := env_var("QT_DIR")

build:
	ninja -C build

run:
	./build/examples/qml_widget_examples

cmake *args:
	cmake -DCMAKE_BUILD_TYPE=Debug -G "Ninja" -DCMAKE_PREFIX_PATH={{qt_dir}} -DBUILD_EXAMPLES=ON -B build {{args}}

clean:
    ninja clean -C build
