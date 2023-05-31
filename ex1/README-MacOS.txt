On a computer with an Apple M1 or M2 processor, you may get the following error when you try to compile a sketch:

... bad CPU type in executable

If this happens for you, it means you have to install a compatibility utility called Rosetta 2.


To install Rosetta, start the Terminal application and type the following command at the prompt:

softwareupdate --install-rosetta

It may a short time to install the utility, but you should then the only compile errors should be ones in your sketch!