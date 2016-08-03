execute pathogen#infect()

filetype plugin indent on
syntax on

no <down> <Nop>
no <up> <Nop>
no <left> <Nop>
no <right> <Nop>

ino <down> <Nop>
ino <up> <Nop>
ino <left> <Nop>
ino <right> <Nop>

nnoremap G Gzz
nnoremap n nzz
nnoremap N Nzz
nnoremap * *zz
nnoremap # #zz
nnoremap J 7j
nnoremap K 7k

set backupdir=~/.vim/backup//
set directory=~/.vim/swap//
set undodir=~/.vim/undo//

set backspace=indent,eol,start
set shiftwidth=4
set tabstop=4
set expandtab
set smarttab
set autoindent
set smartindent
set autoread
set number
set relativenumber
set mouse=a
set ignorecase
set smartcase
set showmatch
set incsearch
set scrolloff=3
set wildmenu

set runtimepath^=~/.vim/bundle/ctrlp.vim
map <C-g> :CtrlPFunky<CR>
map <C-n> :NERDTreeToggle<CR>
let g:NERDTreeChDIRMode=2
let NERDTreeShowHidden=1
nnoremap <C-l> :nohlsearch<CR><C-l>

"airline configuration
let g:airline#extensions#tabline#left_sep = ' '
let g:airline#extensions#tabline#left_alt_sep = '|'
let g:airline#extensions#tabline#enabled = 1
let g:airline#extensions#tabline#fnamemod = ':t'
let g:airline#extensions#whitespace#checks=[]
set laststatus=2

let g:notes_directories = ['~/.vim/notes']

"Solarized
"set background=light
"colorscheme solarized

colorscheme molokai
let g:molokai_original = 1
"let g:rehash256 = 1

"vim-cpp-enhanced-highlight
"let g:cpp_class_scope_highlight = 1
"let g:cpp_experimental_template_highlight = 1
