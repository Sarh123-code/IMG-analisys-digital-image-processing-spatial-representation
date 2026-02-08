# IMG-analisys-digital-image-processing-spatial-representation
This project explores the fundamental principles of image formation and spatial representation within the "4 Worlds" paradigm (physical, continuous, discrete, and memory). Using the libimago library, I developed a suite of tools to manipulate digital images at the pixel level.

Key Technical Implementations:

    Channel Manipulation: Developed tools for channel extraction, composition (img-comp.c), and rotation (img-rotchan.c) to understand RGB color spaces.

    Format & Bit Depth Analysis: Implemented metadata parsers (img-format.c) to identify bit depth (8-bit vs 16-bit), alpha channels, and color models (Grayscale vs RGB).

    Algorithmic Art & Chaos Theory: Created a procedural generator (img-gummira.c) based on the Gumowski-Mira attractor, demonstrating the bridge between mathematical functions and discrete spatial plotting.

    Memory Management: Direct handling of raw pixel buffers in C, ensuring efficient allocation and avoiding memory leaks in image conversion tasks.

Why libimago? In my studies, libimago serves as a lightweight, professional-grade abstraction layer. It allows me to bypass the complexity of various file headers (PNG, JPEG, PPM) and focus on the logic of the algorithms—whether it’s coordinate scaling, barycentric mapping, or color space transformations.
