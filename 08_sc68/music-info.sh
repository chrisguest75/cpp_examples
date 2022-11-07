#!/usr/bin/env bash

echo "NumTracks,Name,Author,Composer,TimeSecs,TimeFormat,Hardware,Size,File"
while IFS='' read -r musicfile
do
    # linux
    # size=$(stat --printf="%s" ${musicfile})
    
    # macos
    size=$(stat -f%z "${musicfile}")
    metadata=$(info68 "${musicfile}" -# , -n , -a , -c , -T , -Y , -H)
    if [[ $? -ne 0 ]]; then
        metadata=",,,,,,"
    fi
    echo "${metadata},${size},${musicfile}" 
done < <(find ./music -type f \( -iname "*" -and ! -iname ".DS_Store" \) )


