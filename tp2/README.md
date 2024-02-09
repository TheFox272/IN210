
#### 1
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

#### 2
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

On a créé un fichier `auto.sh` pour automatiser la compilation et la génération du Code Coverage Report

De plus, nous avons aussi testé l'option -Wl,--wrap=recupAge de gcc afin de remplacer recupAge par son mock. Cela pourrait s'avérer utile dans le cas où elle serait déjà définie dans `age.h`.
