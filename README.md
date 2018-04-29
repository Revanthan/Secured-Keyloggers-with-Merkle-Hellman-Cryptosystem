# Secured-Keyloggers-with-Merkle-Hellman-Cryptosystem
I have proposed a key logger software which helps to record each and every key press and stores it locally in the system without being identified by the user. For safety purpose the data of the keystroke is converted by Merkle Hellman cryptosystem so that even if user finds the file he/she won’t be able to find that those data’s are his/her keystrokes. It is so easy to operate, efficient and it captures all keyboard typed keystrokes.

In our keylogger we going to make use of the keystrokes as input and get it .The keystrokes we get would be in ASCII CODE. Further it will be converted to the characters and displayed. If the text is long then a file is created and saved locally .
The value is then converted to binary code and Merkle-Hellman Cryptosystem is executed. We are also planning to send the file through mail or upload it in the google. 
In C , we have #define invisible which makes the program run in the background without the users knowledge . We are planning to use this feature of C to execute the keyloggers without the users knowledge. A person get the keylog data using internet without the knowledge of the user

Merkle-Hellman Algorithm:
Key generation: 
In Merkle-Hellman, We are going to use two keys.[7] .One of them is a public key which is called as hard knapsack A, and the other is private key wihch called as an easy knapsack B combined with a multiplier number and a modulus number  to compute the keys efficiently. First to encrypt any n-bit messages, we should  choose a superincreasing sequence w = (w1, w2, ..., wn) .
Pick a random integer q, such that q>w.and a random integer, r, such that gcd(r,q) = 1 (i.e. r and q are coprime). Now calculate the sequence β = (β1, β2, ..., βn) βi = rwi mod q. The public key is β, while the private key is (w, q, r). 

Encryption:
To encrypt a message, the first key, A is chosen by comparing it with a set of bits (the plaintext) equal in length to the key. Each term in the public key that corresponds to a 1 in the plaintext is an element of the subset A_m, terms that corresponding to 0 in the plaintext are ignored when constructing A_m .The elements of this subset are added together and the resulting sum is the ciphertext. 

Decryption
Decryption is possible because the multiplier and modulus is used. It is just opposite of the encryption by using Private key ,Message integer and the inverse of r modulo q using the Extended Euclidean Division.

Example 
First, a super increasing sequence w is created 
w = {2, 7, 11, 21, 42, 89, 180, 354} 
This is the basis for a private key. From this, calculate the sum. 
Then, choose a number q that is greater than the sum. 
q = 881 
Also, choose a number r that is in the range and is coprime to q. 
r = 588 
The private key consists of q, w and r. To calculate a public key, generate the sequence β by multiplying each element in w by r mod q 
β = {295, 592, 301, 14, 28, 353, 120, 236} 
because 
(2 * 588) mod 881 = 295 
(7 * 588) mod 881 = 592 
(11 * 588) mod 881 = 301 
(21 * 588) mod 881 = 14 
(42 * 588) mod 881 = 28 
(89 * 588) mod 881 = 353 
(180 * 588) mod 881 = 120 
(354 * 588) mod 881 = 236 
The sequence β makes up the public key. 

Say Alice wishes to encrypt "a". First, she must translate "a" to binary (in this case, using ASCII or UTF-8) 
01100001 
She multiplies each respective bit by the corresponding number in β 
a = 01100001 
0 * 295+ 1 * 592+ 1 * 301+ 0 * 14+ 0 * 28+ 0 * 353+ 0 * 120+ 1 * 236= 1129 
She sends this to the recipient. 
To decrypt, Bob multiplies 1129 by r −1 mod (See Modular inverse) (442=1129 mod (588-1))
(1129 * 442) mod 881 = 372 
Now Bob decomposes 372 by selecting the largest element in w which is less than or equal to 372. Then selecting the next largest element less than or equal to the difference, until the difference is : 
372 - 354 = 18 
18 - 11 = 7 
7 - 7 = 0 
The elements we selected from our private key correspond to the 1 bits in the message 
01100001 
When translated back from binary, this "a" is the final decrypted message. 


The keyloggers.cpp contains the code for keylogger alone and merkle.cpp contains the code for merkle hellman cryptosystem alone. The combined software code is available as combined.cpp.


