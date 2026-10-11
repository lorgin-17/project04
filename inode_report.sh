#!/bin/bash
# inode_report.sh — отчёт по inode и блокам файла
# Использование: ./inode_report.sh имя_файла

# 1. Проверяем, что файл передан и существует
if [ -z "$1" ] || [ ! -f "$1" ]; then
    echo "Использование: $0 имя_файла"
    exit 1
fi

FILE=$1

# 2. Сбрасываем данные на диск: у только что созданного файла
#    блоки могут быть ещё не выделены (отложенная запись в ext4)
sync

# 3. Собираем нужные данные
DEVICE=$(df --output=source "$FILE" | tail -n 1)   # раздел, на котором лежит файл
BLOCK_SIZE=$(stat -f -c "%S" "$FILE")              # размер блока файловой системы
INODE=$(stat -c "%i" "$FILE")                      # номер inode
BLOCKS=$(sudo debugfs -R "blocks <$INODE>" "$DEVICE" 2>/dev/null)

# 4. Мета-информация
echo "Мета-информация"
echo
stat "$FILE"
echo

# 5. Список блоков через запятую
echo "Блоки"
echo
echo "Список блоков: $(echo $BLOCKS | sed 's/ /, /g')"

# 6. Содержимое каждого блока
for block in $BLOCKS
do
    echo "блок $block"
    echo
    sudo dd if="$DEVICE" ibs="$BLOCK_SIZE" skip="$block" count=1 2>/dev/null | hd
    echo
done
