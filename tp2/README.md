# TD 2 IN210 Rapport

## Question 1.1 
```
static void testComputePrice(void **){
    float actual, expected;
    float epsilon = 0.01;
    float basePrice = 1.2;

    actual = computePrice(12, 1);
    expected = basePrice * 2;
    assert_float_equal (expected, actual, epsilon);
}
```

Il faut un epsilon car il est impossible de vérifier l'égalité de deux floats, en effet, leur précision fait que certaines décimales divergeront. On met donc une tolérance epsilon sur l'égalité.


## Question 1.2

```
static void testComputePrice(void **){
    float actual, expected;
    float epsilon = 0.01;
    float basePrice = 1.2;

    actual = computePrice(12, 1);
    expected = basePrice * 2;
    assert_true (expected == actual);
}
```

`assert_float_equal` est ici plus adapté, car il permet de mettre une tolérance sur l'égalité entre deux floats. Si on faisait un test sur une fonction booléenne (renvoyant true ou false), assert_true conviendrait parfaitement.

 
## Question 1.4
Si on test plusieurs assertions à la fois, en cas d'echec, on ne sait pas laquelle est fausse. Or, le but d'un test unitaire est de tester une seule chose à la fois : KISS (Keep It Stupid and Simple).


## Question 1.7
Le mock est exécuté 4 fois, ce qui correspond aux 4 tests, cela vient du fait que recupAge est appelée dans la fonction ComputePrice. 


## Remarques

On a créé un fichier `auto.sh` pour automatiser la compilation et la génération du Code Coverage Report

De plus, nous avons aussi testé l'option -Wl,--wrap=recupAge de gcc afin de remplacer recupAge par son mock. Cela pourrait s'avérer utile dans le cas où elle serait déjà définie dans `age.h`.
