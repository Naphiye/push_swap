# Push_Swap

## 📝 Description

**Push_Swap** est un projet qui consiste à trier des nombres entiers en utilisant uniquement deux piles et un ensemble limité d’instructions.
L'objectif principal est de produire le tri avec le **nombre minimum d'opérations** possible.

Le projet met en avant la maîtrise des structures de données, la gestion de la mémoire, et l’optimisation d’algorithmes.

---

## 🚀 Fonctionnalités

- Trier une liste d'entiers fournie en argument.
- Utilisation de deux piles (`stack_a` et `stack_b`) pour effectuer le tri.
- Instructions autorisées :
  - `sa`, `sb`, `ss` : swap
  - `pa`, `pb` : push
  - `ra`, `rb`, `rr` : rotate
  - `rra`, `rrb`, `rrr` : reverse rotate
- Optimisation pour réduire le nombre d'opérations.
- Gestion des erreurs :
  - Entrées non numériques
  - Nombres dupliqués
  - Débordement d'entiers

---

## Utilisation

Clone le projet et compile-le avec `make` 
./push_swap "liste d'entier"
ou
./push_swap <entier1> <entier2> <...>
