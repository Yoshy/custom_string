#!/bin/bash

echo Test with default "C" locale
echo =======================
cat test_data.txt | ../bin/revlex

echo
echo Test with "CP1251" locale
echo =======================
cat test_data_1251.txt | ../bin/revlex ru_RU.cp1251 | iconv -f cp1251 -t utf-8

echo
echo Test with "CP866" locale
echo =======================
cat test_data_866.txt | ../bin/revlex ru_RU.CP866 | iconv -f cp866 -t utf-8
