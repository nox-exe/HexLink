# HexLink

HexLink is a small C++ program that implements a traceable invitation network inspired by the triangle recruitment system.

Each participant receives a unique 8-digit hexadecimal code.  
The system allows every participant to invite two additional people, forming a hierarchical invite tree.

The first four characters of each invite code identify the inviter, making the relationship between participants traceable without a centralized database.

## Features

- Hexadecimal invitation codes
- Traceable invite chain
- Two-invite limit per participant
- File-based data storage
- Simple graphical interface
- Automatic invite code generation

## How It Works

Example:

Organizer

6E053DFE

Invites two people:

3DFE5BCB  
3DFEDBLE

Each invite code inherits the last four characters of the inviter's code, making the origin traceable.

## Project Structure

src/ – core invite system logic  
ui/ – graphical user interface  
data/ – user code files  

## Build

Compile with a C++ compiler:

g++ src/*.cpp ui/*.cpp -o hexlink

Run:

./hexlink

## Future Improvements

- QR code invite generation
- Invite tree visualization
- Better GUI styling
- Database support

## Author
nox ([nox-exe](https://github.com/nox-exe))  
luca ([carvonkopii](https://github.com/carvonkopii))
