# run.sh — последовательность -> сумма -> cowsay
# Использование: run -s 1 -e 10 [-d 3]

DIR=~/projects/project04/cpp01

numbers=$("$DIR/number" "$@") || exit 1
echo "$numbers" | "$DIR/sum" | cowsay
