#!/bin/bash

dt=$(date '+%Y/%m/%d %H:%M:%S');
echo "$dt" > output.txt;
echo $'\n' >> output.txt;

for file in ./invalid_maps/*.cub
do
  echo $file >> output.txt
  ./../cub3D $file --save 2>> output.txt
  echo $'\n' >> output.txt
done;
