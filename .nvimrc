lua << EOF
if vim.o.loadplugins then
	vim.g.vimrc_dap_lldb_vscode_path = "/usr/local/bin/lldb-vscode"
	vim.g.nvimrc_cwd = vim.fn.getcwd()
	vim.api.nvim_create_autocmd({ "VimEnter" }, {
		pattern = "*",
		group = augroup_vimrc_init,
		once = true,
		callback = function(opts)
			require("vimrc.cpp").setup_cmake({
				name = "qml_widget",
				cmake_args = { "-DCMAKE_BUILD_TYPE=Debug", "-DCMAKE_PREFIX_PATH=" .. vim.fn.expand("$QT_DIR") },
				program = vim.fn.getcwd() .. "/build/qml_widget",
				cwd = vim.fn.getcwd() .. "/build/",
				project_path = vim.fn.getcwd(),
				build_dir = vim.fn.getcwd() .. "/build",
				generator = "Ninja",
			})
		end,
	})

	vim.api.nvim_create_autocmd({ "VimLeavePre" }, {
		pattern = "*",
		group = augroup_vimrc_init,
		once = true,
		callback = function(opts)
			local option = vim.fn.input("Save session (y/n)?: ")
			if option == "y" then
				vim.fn.execute("mksession! " .. vim.g.nvimrc_cwd .. "/session.vim")
			end
		end,
	})
end
EOF

abbreviate build Build
abbreviate cmake CMake
abbreviate run Run
