#!/bin/bash

# Get the directory of the script
script_dir=$(dirname "$0")
bin_dir=$(realpath "${script_dir}/../../bin")
img_dir=$(realpath "${script_dir}/../../img")
output_dir=$(realpath "${script_dir}/../../output")

# Opening size
i=2

# Image
image=cam_74.pgm

mkdir -p "${output_dir}" && cd "${output_dir}" || exit
bash -c "${bin_dir}/exercise_06a_closing_opening ${i} ${img_dir}/${image} exercise_07a_output_01.pgm > /dev/null"
bash -c "${bin_dir}/exercise_06a_closing_opening ${i} exercise_07a_output_01.pgm exercise_07a_output_02.pgm > /dev/null"
bash -c "${bin_dir}/exercise_02b_compare exercise_07a_output_01.pgm exercise_07a_output_02.pgm"
cat < exercise_02b_output_01.txt | sed 's/1/The files are identical/g; s/0/The files are not identical/g'
cd - > /dev/null || exit
