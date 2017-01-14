# Build System Playground
This is a playground to try out different build systems.

## Notes
These might be good to put into a Makefile or something else in order for other people to know how to use this build system.

### To build
If ./build doesn't exist than 'mkdir build; meson build' will need to be ran

Once ./build exists than you will need to to do the following 'cd ./build; ninja-build'

### To run tests
You can make sure you are in ./build and then 'ninja-build test'.

You can run the Google test executal yourself while in the ./build directory

You can run mesontest from the root directory.

The ninja-build and mesontest option will log the output the results from the test to a file in ./build/seson-logs/testlog.[txt json]
