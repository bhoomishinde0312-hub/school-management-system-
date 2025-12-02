# SchoolSystem (C++)

This repository contains a simple University School Management demonstration in C++ (`schoolsystem.cpp`).

Why the code "is not running on GitHub" — common reasons
- GitHub repositories by themselves don't execute code when you view them. You need CI (like GitHub Actions) or a remote environment (Codespaces) to build/run your code.  
- If you tried to compile and saw a "Permission denied" / linker error locally, that usually means an existing copy of the binary was running and Windows locked it — stop the running process or reboot and compile again.

What I did for you
- Added a simple GitHub Actions workflow (.github/workflows/ci.yml) that compiles `schoolsystem.cpp` on Linux (Ubuntu) and runs it with a one-time automatic input to exit. This will show build + run status on pushes and pull requests.

How to build & run locally (Windows PowerShell)
```powershell
g++ schoolsystem.cpp -o schoolsystem.exe
.\schoolsystem.exe
```

If you get "Permission denied" while compiling, check for running copies first:
```powershell
Get-Process -Name schoolsystem -ErrorAction SilentlyContinue
Stop-Process -Name schoolsystem -Force
```

If you want help setting up tests, unit tests, or running the program non-interactively in CI, tell me how you prefer it to run and I'll add that.
