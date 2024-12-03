# Libraries-to-simplify-ROOT

I often perform data analysis using ROOT, a powerful yet sometimes complex framework. To streamline common tasks like plotting and fitting, I have developed libraries that simplify these processes.

---

## Graphing and Utility Tools

### Overview
This library offers tools to handle and visualize graphs in the ROOT framework. Features include:
- Plotting various graph types.
- Customizing axis ranges, log scales, and legends.
- Adding lines, boxes, and advanced graphical elements.
- Simplifying data analysis through utility functions.

---

### **Graph Plotting Tool**: `stampaGraph`

#### Features
`stampaGraph` is a versatile function that supports:
- Plotting one or multiple graphs (`TGraph`, `TH1F`, `TGraphErrors`, etc.).
- Applying log scales (`x`, `y`, or `xy`).
- Configuring axis ranges.
- Adding lines (`TLine`) or customizable boxes.
- Automatic or manual legend placement.

#### General Syntax
```cpp
stampaGraph(graph, "destination.png", "Title", "X-axis", "Y-axis", "Graphic Options", Additional Parameters...);
