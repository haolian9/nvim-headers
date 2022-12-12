#!/usr/bin/env python3

from concurrent.futures import ThreadPoolExecutor
from pathlib import Path


class Facts:
    source_root = Path("/srv/playground/neovim/build/include")
    target_root = Path(__file__).parent.joinpath("include")
    headers = [
        "api/autocmd.h",
        "api/buffer.h",
        "api/command.h",
        "api/extmark.h",
        "api/tabpage.h",
        "api/ui.h",
        "api/vim.h",
        "api/window.h",
        "ex_cmds.h",
        "ex_cmds2.h",
        "ex_cmds_enum",
        "ex_docmd.h",
        "extmark.h",
        "normal.h",
        "popupmenu.h",
        "quickfix.h",
        "textobject.h",
        "usercmd.h",
        "window.h",
        "fold.h",
        "getchar.h",
        "keycodes.h",
        #
        # TBD
        #
    ]


def generate(name: str):
    outfile = Facts.target_root.joinpath(name)
    srcfile = Facts.source_root.joinpath(f"{name}.generated.h")

    def source():
        prefix = b"DLLEXPORT "
        prefix_len = len(prefix)
        with srcfile.open("rb") as fp:
            for line in fp:
                if not line.startswith(prefix):
                    continue
                yield line[prefix_len:]

    with outfile.open("wb") as fp:
        for line in source():
            fp.write(line)


def main():
    with ThreadPoolExecutor() as e:
        e.map(generate, Facts.headers)


if __name__ == "__main__":
    main()
