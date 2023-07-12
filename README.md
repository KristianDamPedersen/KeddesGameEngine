# KEG - KEddes Game engine
A small 2d game engine i coded up.

## Getting started
If you are on linux i've included a few convenience scripts for you to run.

Before we do anything else, we first have to initialize all the libraries being
imported through the git submodule system, we do this by running the following command:
```
git submodule update --init --recursive
```

First we run `configure.sh` which uses CMAKE to make all the build files
We then run `build.sh` which compiles our application.
Then lastly we run `run.sh` which simply cd's into the build directory and runs
our compiled application.

On other platforms it should (hopefully) just be a matter of using your platform 
equivalents for the commands contained inside the different scripts.

## Quirks.
During the configuration step we also copy over all our assets to our build folder,
meaning if you add any assets, make sure to run configure again before building.

### ARM64 support

