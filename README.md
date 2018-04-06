# LSB Image Steganography

This project is in collaboration with (http://github.com/iSiddharthPandey "Siddharth Pandey")

In this technique , the existence of hidden secret data is concealed inside the least significant bits of pixel values of the cover object , as a result the notion of presense of secret information does not even exist.

## Prerequisites

Building them requires a C++ compiler and the GraphicsMagick library.

Installation of GraphicMagick (to use Magick++ API):

On an Ubuntu System, you can install GraphicsMagick by Issuing the Following Command:

`sudo apt install libgraphicsmagick++1-dev`

[![Capture.png](https://s9.postimg.org/idbia42b3/Capture.png)](https://postimg.org/image/595xxfa97/)

You will also need to install make,and libwebp , which is a GraphicsMagick dependency.

[![Capture6.png](https://s9.postimg.org/p3rzjk4wf/Capture6.png)](https://postimg.org/image/wjr95csln/)

## Building

Navigate to the directory containing the project.After that verify that the files exist by typing ls and then typing `make` at the command prompt.

[![Capture1.png](https://s9.postimg.org/denzvl67z/Capture1.png)](https://postimg.org/image/hb1brkr7f/)

[![Capture7.png](https://s9.postimg.org/6bg4fylcv/Capture7.png)](https://postimg.org/image/95j9teniz/)


## Running 

On Successful Compilation , the Following files will be in the `outputs` folder:

`Note : Use png images only, JPEG files use lossy compression and are therefore not supported`

1> encode-file: 
Encodes the secret data into the two low-order bits of the source holder image, producing the output image(Encoded).If  the secret data is too large then only a part of the message will be encoded and a warning is displayed.

[![Capture8.png](https://s9.postimg.org/hf4bz714v/Capture8.png)](https://postimg.org/image/vybh0lu9n/)


2> decode-file: 
Extracts the encoded data out of the two low-order bits of each colour,producing the secret data file. 
Note : While encoding the data the number of lines of the secret data are stored  in an external file( Lines.txt) and the appropriate number of lines of the secret data are decoded so that there is no garbage data in the output file.
 
 [![Capture9.png](https://s9.postimg.org/rcfcs910v/Capture9.png)](https://postimg.org/image/9z52de5pn/)


3> encode-image:
Embeds the secret(private)  image within the public(source holder) image, using 6 bits per colour from public, and 2 bits per channel from private image and produces an output ( encoded image).

[![Screenshot_from_2018-04-02_21-22-05.png](https://s9.postimg.org/mt7pkuqn3/Screenshot_from_2018-04-02_21-22-05.png)](https://postimg.org/image/c6dwffihn/)

`Image that was hidden` 

![hideinthis](https://user-images.githubusercontent.com/21967563/38193537-2cd74808-3690-11e8-832d-8a16c8326f9e.png)


`Image that was hidden upon`


[![hidethis.png](https://s9.postimg.org/eay9gicen/hidethis.png)](https://postimg.org/image/yibp8t9vv/)



4> decode-image:
Extracts the lowest two bits per channel from the input image, to form the source holder image.
Note: Loss of quality of the secret data occours since we are holding the data in 2 bits.

`Decoded Image`

![thiswashidden](https://user-images.githubusercontent.com/21967563/38193591-6429efb8-3690-11e8-86ee-87e9740d51c8.png)






