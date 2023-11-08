#!/bin/bash

SOURCENAME=${0##*/}

SOURCEDIR=$(dirname "$0")

echo "Beginning Webscraping from Bash"

display_usage()
{
    echo ""
    echo "Usage: $SOURCENAME <GenSkip> <Major> [ClassNumber]"
    echo "  <GenSkip>: 1 to skip course URL retrieval, 0 to execute"
    echo "  <Major>: the letter code for any major"
    echo "  [ClassNumber] OPTIONAL: represents the class code for any class"
    echo "Returns: "
    echo "    0 if webscraping executes without error"
    echo "    Nonzero int if there is an error"
    echo " Examples: "
    echo "     $SOURCENAME 0 ECE"
    echo "     $SOURCENAME 1 ECE 397"
}

if [ $# -eq 0 ]; then
    display_usage
    exit 1
fi

if [ $# -ne 2 ] && [ $# -ne 3 ]; then
    echo -e "\nReceived $# arguments, expected 2 or 3"
    display_usage
    exit 1
else
    genSkip=$1
    major=$2
    class=

    if [ $genSkip -ne 1 ] && [$genSkip -ne 0 ]; then
        echo -e "\nGenSkip must be 0 or 1"
        display_usage
        exit 1
    fi 

    if [[ $major =~ ^[[:alpha:]]+$ ]]; then
    uppercase="${major^^}"
    else
        echo -e "\nMajor code must be letters"
        display_usage
        exit 1
    fi

    if [ $# -eq 3 ]; then
        class=$3
        if ! [[ $class =~ ^[0-9]{3}$ ]]; then
            echo -e "\nClass code must be letters"
            display_usage
            exit 1
        fi
    fi
fi

if [ $genSkip -eq 0 ]; then
    python $SOURCEDIR/generate_course_urls.py

    if [ $? -ne 0 ]; then
        echo -e "\nPython error generating course urls"
        exit 1
    fi
fi

python $SOURCEDIR/web_scraping.py $major $class

if [ $? -ne 0 ]; then
    echo -e "\nPython error web scraping from course urls"
    exit 1
fi

echo "Webscraping Successful"