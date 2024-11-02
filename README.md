# Hashing Program (`shhs`)

This project provides a command-line utility for calculating various cryptographic hashes (MD5, SHA-1, SHA-256, SHA-512) of files using the OpenSSL library. The program is modularized for better organization and maintainability.

## Features

- Calculates and displays:
  - MD5
  - SHA-1
  - SHA-256
  - SHA-512

## Requirements

- C compiler (e.g., `gcc`)
- OpenSSL development libraries

## Installation

1. **Install OpenSSL Development Libraries**:
   - On Ubuntu/Debian:
     `sudo apt-get install libssl-dev`
   - On Fedora:
     `sudo dnf install openssl-devel`
   - On macOS:
     `brew install openssl`

2. **Clone or Download the Repository**:
   ```
   git clone https://github.com/Qwer-TeX/shhs.git
   cd shhs
   ```

3. **Build the Project**:
   In the project directory, run:
   `make`

## Usage

Run the program with the path to the file you want to hash:
```
./shhs <file>
```

### Example

To hash a file named `example.txt`, use:
```
./shhs example.txt
```

### Output

The program will output the hashes for the specified file in the following format:
```
MD5: <md5-hash>
SHA-1: <sha1-hash>
SHA-256: <sha256-hash>
SHA-512: <sha512-hash>
```

## Cleaning Up

To clean up the compiled files, run:
```
make clean
```

## Contributing

Feel free to fork the repository and submit pull requests. Contributions to add more hashing algorithms or improve the code structure are welcome!

## License

This project is licensed under the MIT License. See the LICENSE file for details.

---

You can save this content in a file named `README.md` in your project directory. Let me know if you need any changes!
