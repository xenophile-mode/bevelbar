if [ "$HOSTNAME" = "archdt1" ]
then
    bevelbar_arguments=(
        -b 1 -B 1 -o black -O black -p '#474747' -m 2
        -s  0  -c  '#343434'  -c  '#aaaaaa'  -c  black  -c  black
        -s  1  -c  '#6ac100'  -c  black      -c  black  -c  black
        -s  2  -c  '#343434'  -c  '#aaaaaa'  -c  black  -c  black
        -s  3  -c  '#6ac100'  -c  black      -c  black  -c  black
        -s  4  -c  '#c10019'  -c  '#aaaaaa'  -c  black  -c  black
        -s  5  -c  '#c10019'  -c  black      -c  black  -c  black
    )
else
    bevelbar_arguments=(
        -f 'Terminus-Regular:pixelsize=11'
        -b 1 -B 1 -o '#353535' -O '#151515' -p '#1b1b1b' -m 2
        -s  0  -c  '#1b1b1b'  -c  '#555555'  -c  '#353535'  -c  '#151515'
        -s  1  -c  '#474747'  -c  '#ffffff'  -c  '#757575'  -c  '#383838'
        -s  2  -c  '#1b1b1b'  -c  '#555555'  -c  '#353535'  -c  '#151515'
        -s  3  -c  '#474747'  -c  '#ffffff'  -c  '#757575'  -c  '#383838'
        -s  4  -c  '#571d1d'  -c  '#ffffff'  -c  '#903030'  -c  '#451717'
        -s  5  -c  '#571d1d'  -c  '#ffffff'  -c  '#903030'  -c  '#451717'
    )
fi
