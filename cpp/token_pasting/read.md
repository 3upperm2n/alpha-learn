Sometimes you will see the following code.

```
#define version(s,v) s ## _V_ ## v 
```

The double-number-sign or "token-pasting" operator (##), which is sometimes called the "merging" operator, is used in both object-like and function-like macros. It permits separate tokens to be joined into a single token and therefore cannot be the first or last token in the macro definition. [link](https://msdn.microsoft.com/en-us/library/09dwwt6y.aspx)
