
OUTPUT_NAME=hsh

BINAIRY_DIR=bin

SOURCE_DIR=src

INCLUDE_DIR=include

CFLAGS="-Wall -Wextra -I $INCLUDE_DIR"

COMPILER=gcc


#function detect_compiler() {
#    
#}

function build() {

    # create the output_dir if it not exists
    if [ ! -d $BINAIRY_DIR ]; then
        mkdir $BINAIRY_DIR
    fi

    $COMPILER -o "$BINAIRY_DIR/$OUTPUT_NAME" $CFLAGS $SOURCE_DIR/*.c
}

#detect_compiler

build
