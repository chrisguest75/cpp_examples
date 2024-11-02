# README

Building SC68 tools inside a docker container.  

NOTE:

* Use `imhex.app` to look at the files packed and unpacked  

TODO:

* durations on the tracks not working
* not all of the files are working in info68 (is it just icepacked?)
* single step debugging of the info68 app.  

Ref: [76_building_cpp_package](https://github.com/chrisguest75/docker_examples/blob/master/76_building_cpp_package/README.md)  

Unice instructions [here](./unice68-2.0.0.690/README)  

## Get code

Ref: [shell_examples/63_md5_file_id](https://github.com/chrisguest75/shell_examples/tree/master/63_md5_file_id)  

```sh
function verify_md5() {
    : ${1?"${FUNCNAME[0]}(url) - missing url argument"}
    : ${2?"${FUNCNAME[0]}(url) - missing md5 argument"}

    local FILENAME=$1
    local MD5=$2
    local FILE_MD5=$(cat $FILENAME | md5)
    if [[ $FILE_MD5 == $MD5 ]]; then
        echo "SUCCESS: MD5 for $FILENAME matches $MD5"
    else
        >&2 echo "FAIL: MD5 for $FILENAME does not match $MD5 - actual $FILE_MD5"
    fi 
}
FILENAME=./unice68-2.0.0.690.tar.gz
rm ${FILENAME}
curl -s -o  ${FILENAME} -L https://sourceforge.net/projects/sc68/files/unice68/source-packages/unice68-2.0.0.690.tar.gz/download
MD5="a612d9f987478b565bf4c91ff0d445c4"
verify_md5 "${FILENAME}" "$MD5"

FILENAME=./sc68-2.2.1.tar.gz
rm ${FILENAME}
curl -s -o ${FILENAME} -L https://sourceforge.net/projects/sc68/files/sc68/2.2.1/sc68-2.2.1.tar.gz/download
MD5="84aa948f76274361f7e78c3563951eff"
verify_md5 "${FILENAME}" "$MD5"
```

## Build (unice68)

```sh
# unpack if required
tar -xzvf ./unice68-2.0.0.690.tar.gz            

# build image with build tools (add --no-cache if reqd)
docker build --progress plain -f ./Dockerfile.unice68 -t unice68 .

# run unice68 tool
docker run --rm -it unice68   

# share in files
docker run --rm -it --volume $(pwd)/music:/music unice68

/scratch/out/bin/unice68 --test /music/source/Arcade_Classix_Hiscore.sndh 
/scratch/out/bin/unice68 /music/source/Arcade_Classix_Hiscore.sndh /music/out/Arcade_Classix_Hiscore.sndh
```

## Build (sc68)

```sh
tar -xzvf ./sc68-2.2.1.tar.gz  

# build image with build tools (add --no-cache if reqd)
docker build --progress plain -f ./Dockerfile.sc68 -t sc68 .

# run sc68 tool
docker run --rm -it sc68               

# share in files
docker run --rm -it --volume $(pwd)/music:/music sc68

export MUSIC_FILENAME=Arcade_Classix_Hiscore
export MUSIC_FILENAME=AJH_99

/scratch/out/bin/info68 /music/source/${MUSIC_FILENAME}.sndh -# , -n , -a , -c , -T , -Y , -H
/scratch/out/bin/sc68 /music/source/${MUSIC_FILENAME}.sndh > /music/out/${MUSIC_FILENAME}.pcm

# if playing mono it will not sound right
ffplay -ac 2 -f s16le -ar 44100 ./music/out/${MUSIC_FILENAME}.pcm

# render mp3
ffmpeg  -ac 2 -f s16le -ar 44100 -i ./music/out/${MUSIC_FILENAME}.pcm  -ac 1 ./music/out/${MUSIC_FILENAME}.mp3
vlc ./music/out/${MUSIC_FILENAME}.mp3
```

## Corrscope

```sh
# master
ffmpeg -i ./music/out/${MUSIC_FILENAME}.mp3 ./music/out/${MUSIC_FILENAME}.wav
# left
ffmpeg -i ./music/out/${MUSIC_FILENAME}.mp3 -af "pan=mono|c0=FL" ./music/out/${MUSIC_FILENAME}_L.wav
# right
ffmpeg -i ./music/out/${MUSIC_FILENAME}.mp3 -af "pan=mono|c0=FR" ./music/out/${MUSIC_FILENAME}_R.wav
```

## Resources

* Command line tools [here](http://sc68.atari.org/developers_tools.html)
* sc68 - Atari ST and Amiga music player Code [here](https://sourceforge.net/p/sc68/code/HEAD/tree/)
* https://github.com/Zeinok/sc68
* https://github.com/wothke/sc68-2.2.1