




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



