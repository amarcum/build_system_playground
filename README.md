# Build System Playground
This is a playground to try out different build systems.

*** 

## Notes
These might be good to put into a Makefile or something else in order for other people to know how to use this build system.

### To build
If ./build doesn't exist than 'meson build' will need to be ran

Once ./build exists than you will need to to do the following 'ninja-build -C build'

### To run tests
You can run the test by using  'ninja-build -C build test'.

You can run the Google test executable yourself while in the ./build directory

You can run mesontest from the root directory.

The ninja-build and mesontest option will log the output the results from the test to a file in ./build/seson-logs/testlog.[txt json]
