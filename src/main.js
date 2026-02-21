document.addEventListener('DOMContentLoaded', () => {
  const app = document.getElementById('app');

  // Простая структура UI
  app.innerHTML = `
    <style>
      body { margin: 0; font-family: sans-serif; height: 100vh; display: grid; grid-template-columns: 260px 1fr 420px; grid-template-rows: 48px 1fr 180px; gap: 4px; }
      #toolbar { grid-column: 1 / span 3; display: flex; align-items: center; padding: 8px; background: #2b2b2b; color: white; }
      #fileTree { border-right: 1px solid #ddd; padding: 8px; overflow: auto; }
      #editor { padding: 8px; }
      #console { grid-column: 1 / span 3; padding: 8px; background: #111; color: #eee; overflow: auto; }
      textarea.editor { width: 100%; height: calc(100% - 24px); resize: none; font-family: monospace; font-size: 13px; padding: 8px; border: 1px solid #333; background: #1e1e1e; color: #dcdcdc; }
      .btn { padding: 6px 12px; margin-right: 8px; border: none; border-radius: 4px; background: #4a90e2; color: white; cursor: pointer; }
      .btn.secondary { background: #555; }
      #terminal { height: 100%; white-space: pre-wrap; font-family: monospace; padding: 6px; background: #0b0b0b; color: #9cdcfe; }
      .tree-item { padding: 4px 6px; cursor: pointer; }
      .tree-item.active { background: #2a2a2a; }
    </style>
    <div id="toolbar">
      <button class="btn" id="btnNew">New File</button>
      <button class="btn" id="btnOpen">Open File</button>
      <button class="btn" id="btnSave">Save</button>
      <button class="btn" id="btnCompile">Compile</button>
      <button class="btn" id="btnRun">Run</button>
      <span style="margin-left: auto; opacity: .8;">C++ IDE (Tauri + JS)</span>
    </div>
    <div id="fileTree" style="height: calc(100vh - 48px);">
      <div><strong>Project</strong></div>
      <div id="tree"></div>
    </div>
    <div id="editor">
      <div><strong>Editor</strong></div>
      <textarea id="code" class="editor" spellcheck="false"></textarea>
    </div>
    <div id="console">
      <div><strong>Console</strong></div>
      <div id="terminal"></div>
    </div>
  `;

  // Простейшая структура файлов в памяти (будет заменена на чтение файлов с диска)
  let currentPath = '';
  let fileMap = {}; // { path: content }

  // Панель дерева файлов (простейшая эмуляция)
  const treeEl = document.getElementById('tree');
  function renderTree() {
    treeEl.innerHTML = '';
    const root = document.createElement('div');
    root.className = 'tree-item';
    root.textContent = 'src/';
    root.onclick = () => {
      // загрузить пример файла main.cpp
      loadFile('/src/main.cpp');
    };
    treeEl.appendChild(root);
  }

  function loadFile(path) {
    // В реальном случае используем tauri.invoke('readFile', { path })
    window.__tauriInvoked('readFile', { path }).then((content) => {
      const codeBox = document.getElementById('code');
      codeBox.value = content;
      currentPath = path;
      // подсветка можно добавить позже
      highlightCode();
      // отметка выбранного файла
      document.querySelectorAll('.tree-item').forEach(el => el.classList.remove('active'));
      // простая логика
      rootClickFake(path);
    }).catch(() => {
      // если файл не найден, создаем новый
      const codeBox = document.getElementById('code');
      codeBox.value = '';
      currentPath = path;
      document.querySelectorAll('.tree-item').forEach(el => el.classList.remove('active'));
      rootClickFake(path);
    });
  }

  // заглушка для выделения активного элемента дерева
  function rootClickFake(path) {
    // в реальном UI можно найти элемент по пути и пометить active
  }

  // кнопки
  document.getElementById('btnNew').onclick = () => {
    const name = prompt('New file name (e.g., /src/new.cpp):', '/src/new.cpp');
    if (!name) return;
    fileMap[name] = '';
    currentPath = name;
    document.getElementById('code').value = '';
    renderTree();
  };

  document.getElementById('btnOpen').onclick = () => {
    // Пример открытия файла через диалог
    window.__tauriInvoked('openFileDialog', {}).then((path) => {
      if (path) loadFile(path);
    });
  };

  document.getElementById('btnSave').onclick = () => {
    const code = document.getElementById('code').value;
    if (!currentPath) {
      const path = prompt('Save as (path):', '/src/new.cpp');
      if (!path) return;
      currentPath = path;
    }
    // в реальности: tauri.invoke('writeFile', { path: currentPath, content: code })
    window.__tauriInvoked('writeFile', { path: currentPath, content: code }).then(() => {
      appendToConsole(`Saved: ${currentPath}\n`);
    }).catch((err) => {
      appendToConsole(`Error saving: ${err}\n`);
    });
  };

  document.getElementById('btnCompile').onclick = () => {
    // Запуск сборки через Rust
    appendToConsole('Compiling project...\n');
    window.__tauriInvoked('compileProject', {}).then((out) => {
      appendToConsole(out + '\n');
    }).catch((err) => {
      appendToConsole(`Compile error: ${err}\n`);
    });
  };

  document.getElementById('btnRun').onclick = () => {
    appendToConsole('Running project...\n');
    window.__tauriInvoked('runBinary', {}).then((out) => {
      appendToConsole(out + '\n');
    }).catch((err) => {
      appendToConsole(`Run error: ${err}\n`);
    });
  };

  function appendToConsole(text) {
    const term = document.getElementById('terminal');
    term.textContent += text;
    term.scrollTop = term.scrollHeight;
  }

  function highlightCode() {
    // здесь можно подключить простую подсветку или просто оставить как есть
  }

  // Инициализация
  renderTree();
  // Заглушка: загрузим примерный файл
  loadFile('/src/main.cpp');
});

// Безопасный обертчик для tauri.invoke, чтобы код тестировался в окружении браузера
if (!window.__tauriInvoked) {
  window.__tauriInvoked = async (cmd, args) => {
    // В реальном окружении заменить на window.__TAURI__.invoke
    console.warn('TAURI invoke заменено заглушкой. Команда:', cmd, args);
    return new Promise((resolve, reject) => {
      // Демо: возвращаем фиктивные данные
      if (cmd === 'readFile') {
        resolve('// пример файла main.cpp\nint main(){return 0;}');
      } else if (cmd === 'compileProject') {
        resolve('Build finished with 0 warnings and 0 errors.');
      } else if (cmd === 'runBinary') {
        resolve('Program output:\\nHello from C++ in Rust Tauri!');
      } else if (cmd === 'writeFile') {
        resolve();
      } else if (cmd === 'openFileDialog') {
        resolve('/src/main.cpp');
      } else {
        resolve('');
      }
    });
  };
}
