# Fast Authentication with Aggregate Signatures (FAAS)

FAAS leverages secure single signer signature aggregation property and offers fast signing digital signature schemes

## FAAS RSA Dependencies

1. GMP - https://gmplib.org/

2. b2 - https://github.com/BLAKE2/libb2

## FAAS pqNTRUsign Dependencies

This code is implemented on top of the base implementation of pqNTRUsign (https://github.com/zhenfeizhang/pqNTRUSign)

1. b2 - https://github.com/BLAKE2/libb2

## Usage

After installing the dependencies, go to CEDA folder and make. Then, under CEDA/Debug folder you can see the executable. Code is tested with Intel i7 6700HQ and ARM Cortex A53 running Ubuntu 16.04 and Raspbian, respectively.

## License

Please check the licenses for the dependencies before using this code.

Special thanks to Adam Brockett for providing RSA code in GMP.



