#include <Magick++.h>
#include <iostream>
#include <cassert>
#include <fstream>
#include <bitset>

using namespace std;
using namespace Magick;

unsigned char byte; //Extracting data in the form of bytes.
unsigned bits;      // Data bits that is to be Decoded.

//Extracting LSBs from pixels  and aggregating the Bitpairs into the output file.
void pushBitPair(ostream &out, Quantum q)
{
    char bitsf = q & 3;
    // cout << "Pushing " << hex << q << " as bits " << bitset<2>(bits) << '\n';
    byte <<= 2;
    byte |= bitsf;
    bits += 2;
    if (bits == 8)
    {

        out.put(byte);
        // cout << "Dumping byte " << bitset<8>(byte) << '\n';
        byte = 0;
        bits = 0;
    }
}

int main(int argc, char **argv)
{
    //Initializing Library
    InitializeMagick(*argv);

    //Checking  if the command line arguments are passed appropriately.
    if (argc != 3)
    {
        cout << "Usage: " << argv[0] << " inputimage.png secret.data\n";
        exit(1);
    }

    string inputPath = argv[1];
    string secretPath = argv[2];

    cout << "Loading " << inputPath << '\n';
    Image im(inputPath);
    Geometry g = im.size();
    //LSB Steganography works only on no compressed images so we have to make sure image
    // is of correct format i.e 24 bit color represenation and type true color.
    if (!(im.depth() <= 8))
    {

        cout << "Input Image depth should be less than 8\n";
        exit(-1);
    }
    if (im.type() != TrueColorType)
    {
        {

            cout << "Input Image should be of TrueColourType\n";
            exit(-1);
        }
    }

    cout << "Writing " << secretPath << '\n';
    ofstream out("tempfile", ios::binary);

    byte = 0;
    bits = 0;

    for (unsigned y = 0; y < g.height(); y++)
    {
        for (unsigned x = 0; x < g.width(); x++)
        {
            Color c = im.pixelColor(x, y);
            pushBitPair(out, c.redQuantum());
            pushBitPair(out, c.greenQuantum());
            pushBitPair(out, c.blueQuantum());
        }
    }

    out.close();

    ifstream fin;
    fin.open("lines.txt");

    int xline;
    fin >> xline;
    fin.close();

    ofstream fout;

    ifstream xin;
    xin.open("tempfile");
    fout.open(secretPath.c_str());
    string line;
    while (xline--)
    {
        std::getline(xin, line);
        fout << line;
        fout << "\n";
    }

    fout.close();

    return 0;
}
