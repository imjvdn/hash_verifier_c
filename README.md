# hash_verifier
A CLI program that you pass a supplied hash and the name of the file to hash

Here is a simple example of a command line program that can be used to compare a supplied hash with the hash of a file. This program uses the md5sum command to calculate the MD5 hash of a file, and then compares that hash to the supplied hash to determine if they match.

To use this program, you would pass the supplied hash and the file name as command line arguments. For example, to compare the supplied hash 1234567890 with the file test.txt, you would run the program like this:

./hash_verifier 1234567890 test.txt

This would print the file name, the supplied and calculated hashes, the result (valid or invalid), and the algorithm used (MD5) to the console.
