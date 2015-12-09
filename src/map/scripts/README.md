# Scripts for manipulating maps

## To generate a grid map with
```
# A 3×3 grid in a square of 1.0
./gridmap 1.0 1.0 3 3
# A 8×6 grid in a 15.0×10.0 rectangle
./gridmap 15.0 10.0 8 6
# A 4×4 map stored in a file
./gridmap 1.0 1.0 4 4 > grid44.map
```

## To convert map file into a .dot file
```
# Default output is stdout
./map2dot input.map
# To store it in a file
./map2dot input.map > output.dot
```

## To convert a dot file in a svg file (viewable in any image viewer)
```
# Default output is stdout
./dot2svg input.dot
# To store it in a file
./dot2svg input.dot > output.svg
```

## To view a map directly (requires Imagemagick)
```
./display_map file.map
```
