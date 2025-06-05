project('taskmgr_meson', 'c',
  default_options: [
    'warning_level=3',     # Аналог -Wall -Wextra
    'c_std=c99',           # Явно указываем стандарт C99
    'debug=true',          # Аналог -g (отладочная информация)
  ])

# Директории
src_dir = 'src/'
include_dir = include_directories('include/')

# Исходные файлы (аналог wildcard)
src_files = files(
  src_dir + 'main.c',
  src_dir + 'cli_handler.c',
  src_dir + 'file_manager.c',
  src_dir + 'task_list.c',
  src_dir + 'task.c',
)

# Сборка исполняемого файла (аналог $(TARGET))
executable('taskmgr',
  src_files,
  include_directories: include_dir,
  install: false,          # Не устанавливать в систему
  build_by_default: true,  # Собирать по умолчанию (аналог all)
)