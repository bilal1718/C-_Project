

    // Encrypts a string with a positive shift value
    SECTION('should encrypt the string with a positive shift value') {
        string password = "hello";
        int shift = 3;
        string expected = "khoor";
        string actual = encryptCaesarCipher(password, shift);
        REQUIRE(actual == expected);
    }

    // Encrypts a string with a negative shift value
    SECTION('should encrypt the string with a negative shift value') {
        string password = "hello";
        int shift = -3;
        string expected = "ebiil";
        string actual = encryptCaesarCipher(password, shift);
        REQUIRE(actual == expected);
    }

    // Encrypts a string with a shift value of 0
    SECTION('should encrypt the string with a shift value of 0') {
        string password = "hello";
        int shift = 0;
        string expected = "hello";
        string actual = encryptCaesarCipher(password, shift);
        REQUIRE(actual == expected);
    }

    // Encrypts a string with a shift value greater than 26
    SECTION('should encrypt the string with a shift value greater than 26') {
        string password = "hello";
        int shift = 30;
        string expected = "lipps";
        string actual = encryptCaesarCipher(password, shift);
        REQUIRE(actual == expected);
    }

    // Encrypts a string with a shift value less than -26
    SECTION('should encrypt the string with a shift value less than -26') {
        string password = "hello";
        int shift = -30;
        string expected = "vbyyb";
        string actual = encryptCaesarCipher(password, shift);
        REQUIRE(actual == expected);
    }

    // Encrypts a string with a shift value of 27
    SECTION('should encrypt the string with a shift value of 27') {
        string password = "hello";
        int shift = 27;
        string expected = "ifmmp";
        string actual = encryptCaesarCipher(password, shift);
        REQUIRE(actual == expected);
    }
