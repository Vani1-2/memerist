#!/bin/bash
set -e

distrobox enter ubuntu -- bash -c '
  cp build/src/memerist deb-build/memerist-amd64/usr/bin/
  dpkg-deb --build deb-build/memerist-amd64
'
