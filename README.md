# ✈️ My Radar - Air Traffic Control Simulation 🛫  

"My Radar" is a graphical program developed in **C**, designed to simulate and visualize air traffic, including aircraft and control towers.  
This project is part of the **B-MUL-100** module, focusing on graphical programming with **CSFML**.  

---

## 🚀 Features  

- **🛩️ Air Traffic Simulation**: Displays moving aircraft and stationary control towers on a 2D panel.  
- **💥 Collision Handling**: Aircraft collide and are destroyed unless protected within a control tower's area.  
- **🛑 Control Areas**: Each control tower defines a protection zone to prevent aircraft collisions.  
- **📜 Flexible Scripting**: Entities and their behaviors are defined in an external script, allowing for dynamic simulations.  

---

## ⚙️ Command-line Options  

- **`-h`**: Displays help and available options.  

---

## 🎮 User Interactions  

- **Key 'L'**: Toggles the visibility of **hitboxes** and **control areas**.  
- **Key 'S'**: Toggles the visibility of **entity sprites**.  

---

## 🛠️ Prerequisites  

- 🛠️ **GCC** (compiler)  
- 🎨 **CSFML Library**  

---

## 🔧 Installation  

1️⃣ **Clone the repository**:  
```bash
git clone https://github.com/ArthuryanLoheac/My_radar.git
```  
⬇️ **Click to copy**:
<button onclick="navigator.clipboard.writeText('git clone https://github.com/ArthuryanLoheac/My_radar.git')">Copy</button>  

2️⃣ **Navigate to the project directory**:  
```bash
cd my_radar
```  
⬇️ **Click to copy**:
<button onclick="navigator.clipboard.writeText('cd my_radar')">Copy</button>  

3️⃣ **Compile with Makefile**:  
```bash
make
```  
⬇️ **Click to copy**:
<button onclick="navigator.clipboard.writeText('make')">Copy</button>  

---

## ▶️ Usage  

🎬 Run the program with a script file as an argument:  
```bash
./my_radar path_to_script
```  
⬇️ **Click to copy**:
<button onclick="navigator.clipboard.writeText('./my_radar path_to_script')">Copy</button>  

🆘 Display help:  
```bash
./my_radar -h
```  
⬇️ **Click to copy**:
<button onclick="navigator.clipboard.writeText('./my_radar -h')">Copy</button>  

---

## 📜 Script File Format  

The script defines **aircraft** and **control towers** with the following syntax:  

✈️ **Aircraft**:  
```plaintext
A [departure x] [departure y] [arrival x] [arrival y] [speed] [takeoff delay]
```  

🏢 **Control Tower**:  
```plaintext
T [x] [y] [control radius]
```  

✅ **Entities should be separated by new lines**, and attributes should be separated by **spaces or tabs**.  

🔹 **Example script content**:  
```css
A 815 321 1484 166 5 0
A 1589 836 811 936 2 0
A 202 894 103 34 3 0
T 93 47 19
T 49 56 25
```  
