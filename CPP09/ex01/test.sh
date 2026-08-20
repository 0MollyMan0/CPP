#!/bin/bash

echo "========== TESTS VALIDES =========="
echo

echo "[1] Exemple sujet"
./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"

echo "[2] Exemple sujet"
./RPN "7 7 * 7 -"

echo "[3] Exemple sujet"
./RPN "1 2 * 2 / 2 * 2 4 - +"

echo
echo "[4] Addition"
./RPN "1 2 +"

echo "[5] Soustraction"
./RPN "9 4 -"

echo "[6] Multiplication"
./RPN "3 4 *"

echo "[7] Division"
./RPN "8 2 /"

echo
echo "[8] Plusieurs opérations"
./RPN "1 2 + 3 *"

echo "[9] Ordre soustraction"
./RPN "8 3 -"

echo "[10] Ordre division"
./RPN "8 2 /"

echo "[11] Résultat négatif"
./RPN "2 8 -"

echo "[12] Résultat avec plusieurs étapes"
./RPN "5 1 2 + 4 * + 3 -"

echo "[13] Résultat zéro"
./RPN "1 2 - 3 +"

echo "[14] Expression longue"
./RPN "9 8 + 7 6 + * 5 - 4 +"

echo
echo "========== TESTS ERREURS =========="
echo

echo "[15] Pas assez d'opérandes"
./RPN "1 +"

echo "[16] Pas assez d'opérandes"
./RPN "+"

echo "[17] Pas assez d'opérandes"
./RPN "1 2 + +"

echo "[18] Trop de nombres"
./RPN "1 2"

echo "[19] Trop de nombres"
./RPN "1 2 3 +"

echo "[20] Division par zéro"
./RPN "8 0 /"

echo "[21] Division par zéro après calcul"
./RPN "4 2 - 0 /"

echo "[22] Caractère invalide"
./RPN "1 2 a"

echo "[23] Caractère invalide"
./RPN "1 2 %"

echo "[24] Parenthèses"
./RPN "(1 2 +)"

echo "[25] Expression classique"
./RPN "(1 + 1)"

echo "[26] Plusieurs caractères invalides"
./RPN "1 2 &"

echo
echo "========== TESTS FORMAT =========="
echo

echo "[27] Espaces multiples"
./RPN "1    2    +"

echo "[28] Espaces au début"
./RPN "   1 2 +"

echo "[29] Espaces à la fin"
./RPN "1 2 +   "

echo "[30] Seulement des espaces"
./RPN "   "

echo "[31] Chaîne vide"
./RPN ""

echo
echo "========== TESTS NOMBRES =========="
echo

echo "[32] Zéro"
./RPN "0"

echo "[33] Nombre 9"
./RPN "9"

echo "[34] Tous les chiffres"
./RPN "1 2 + 3 + 4 + 5 + 6 + 7 + 8 + 9 +"

echo "[35] Résultat supérieur à 9"
./RPN "9 9 *"

echo "[36] Résultat négatif"
./RPN "9 9 9 * -"

echo
echo "========== TESTS SORTIE D'ERREURS =========="
echo

./RPN "1 +" > output.txt 2> error.txt

echo
echo "========== FIN =========="