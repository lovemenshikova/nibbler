#!/bin/bash
set -e

SFML_V=3.0.2
DST="$PWD/SFML-3.0.2"

echo "Change the access mode to SFML lib"

chmod 777 "$DST/"

echo "Export dynld library path"
export "DYLD_LIBRARY_PATH=$DYLD_LIBRARY_PATH:$DST/lib"
export "DYLD_LIBRARY_PATH=$DYLD_LIBRARY_PATH:$DST/lib"

echo "Configure is done!"
# ./MyGame
