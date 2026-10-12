<h1 align="center">📝 ToDo-List</h1>

<p align="center">
  A lightweight command-line To-Do manager written in C++ that remembers your tasks between runs.
</p>

<p align="center">
  <img src="https://img.shields.io/badge/language-C%2B%2B-00599C?logo=cplusplus&logoColor=white" alt="C++">
  <img src="https://img.shields.io/badge/type-CLI-informational" alt="CLI">
  <img src="https://img.shields.io/badge/status-active-brightgreen" alt="Status">
  <img src="https://img.shields.io/badge/PRs-welcome-orange" alt="PRs welcome">
</p>

---

## ✨ Features

| Feature | Description |
|---|---|
| ➕ Add tasks | Create a new task in seconds |
| 📋 View tasks | See every task with its status (`[ ]` pending, `[x]` done) |
| ✅ Mark as done | Tick off tasks as you finish them |
| 🗑️ Delete tasks | Remove tasks you no longer need |
| 💾 Auto-save | Everything is stored in `tasks.txt`, so nothing is lost when you exit |
| 🛡️ Input validation | Invalid choices and task numbers are handled safely |

## 🚀 Getting Started

### Prerequisites
- A C++ compiler such as `g++` (MinGW on Windows, or GCC on Linux/macOS)
- Git (optional, for cloning)

### Installation

```bash
# 1. Clone the repository
git clone https://github.com/priyanshu-17shekhawat/ToDo-List.git

# 2. Move into the folder
cd ToDo-List

# 3. Compile
g++ Todo.cpp -o todo

# 4. Run
./todo          # Windows: todo.exe
```

## 🖥️ Usage

```
===== TO-DO LIST =====
1. Add task
2. View tasks
3. Mark task as done
4. Delete task
5. Exit
Choose: 2

Your tasks:
1. [x] Finish DSA assignment
2. [ ] Push first repo to GitHub
3. [ ] Revise OOP notes
```

Type the number of the option you want and press **Enter**. Tasks are saved automatically after every action.

## 🧠 How It Works

- Tasks are stored in a `vector<Task>`, where each `Task` has a `title` and a `done` flag.
- On startup, the program reads `tasks.txt` using `ifstream`.
- After every action, it writes the list back using `ofstream`.
- Each line in `tasks.txt` follows the format `status|title`, for example `1|Finish DSA assignment`.

## 📚 Concepts Practiced

`struct` · `vector` · functions · file handling (`ifstream` / `ofstream`) · input validation · `switch` statements · pass by reference

## 🗺️ Roadmap

- [x] Add, view, complete and delete tasks
- [x] Persistent storage using a text file
- [ ] Edit an existing task
- [ ] Due dates
- [ ] Priority levels (high / medium / low)
- [ ] Sort tasks (pending first)
- [ ] Clear all completed tasks

## 🤝 Contributing

Suggestions and improvements are welcome!

1. Fork the repo
2. Create a branch: `git checkout -b feature/your-feature`
3. Commit your changes: `git commit -m "Add your feature"`
4. Push: `git push origin feature/your-feature`
5. Open a Pull Request

## 👨‍💻 Author

**Priyanshu**, IIIT Kalyani
GitHub: [@priyanshu-17shekhawat](https://github.com/priyanshu-17shekhawat)

---

<p align="center">⭐ If you found this useful, consider giving it a star!</p>
