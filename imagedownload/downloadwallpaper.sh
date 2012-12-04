#!/bin/sh
cd /home/stonewf/图片

url=http://www.dream-wallpaper.com/free-wallpaper/cartoon-wallpaper/the-most-beautiful-cg-girl-1-wallpaper/1920x1200/free-wallpaper-1.jpg
len=$(expr length $url)
k=$((len-5))
s1=$(expr substr $url 1 $k)
s3=.jpg

for ((i=1;i<300;i++))
do
s2=$i$s3
url=$s1$s2
#wget $url
if wget $url
then
echo $i
else
exit
fi
done


