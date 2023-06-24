# Known issues

## Asset not updating
Due to Cmake copying over assets at configure time, you have to rerun
`configure.sh` if any assets are changed.

## LSP choking
Try removing the .cache folder and restarting the LSP
