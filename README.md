# GitSync for n8n

> Automated Git version control for n8n workflows with intelligent change detection and AI-assisted documentation.

GitSync for n8n is an open-source workflow that automatically synchronizes your n8n workflows to a GitHub repository.

Instead of manually exporting workflows or committing JSON files, GitSync continuously detects new and updated workflows, synchronizes them to GitHub, and optionally generates and maintains professional README documentation using AI.

To ensure documentation quality, all AI-generated README files and updates require manual approval before they are committed.#

---

# Why GitSync?

Version control is a fundamental part of modern software development, but managing n8n workflows in Git often requires manual exports, manual commits, and manual documentation.

As workflows evolve, keeping a Git repository up to date becomes repetitive and error-prone. Changes may go untracked, documentation can become outdated, and collaboration becomes more difficult.

GitSync for n8n automates this entire process by continuously synchronizing workflows to a GitHub repository. It detects newly created workflows, identifies meaningful changes to existing workflows, and updates the repository only when necessary to preserve a clean Git history.

For teams that maintain workflow documentation, GitSync can also generate and maintain professional README files using AI. Every AI-generated README creation or update requires manual approval before it is committed, giving you the benefits of automation without sacrificing documentation quality.

---

# ✨ Features

| Feature | Description |
|---------|-------------|
| 🔄 Automatic Workflow Synchronization | Keeps your GitHub repository synchronized with your n8n workflows on a scheduled basis. |
| 🆕 New Workflow Detection | Automatically detects newly created workflows and adds them to the repository. |
| ♻️ Intelligent Change Detection | Compares workflow definitions and commits only meaningful changes, avoiding unnecessary Git history noise. |
| 📁 Organized Repository Structure | Stores each workflow in its own dedicated folder with its workflow JSON and documentation. |
| 📄 AI-Generated Documentation | Automatically generates professional `README.md` documentation for newly synchronized workflows. |
| 🧠 Intelligent Documentation Updates | Evaluates whether workflow changes require documentation updates instead of regenerating README files unnecessarily. |
| 👤 Human Approval Workflow | Requires manual approval before creating or updating AI-generated documentation. |
| 📧 Email-Based Review Process | Sends proposed documentation changes by email, allowing reviewers to approve or reject them before publication. |
| 🐙 Native GitHub Integration | Uses the native n8n GitHub node to create and update workflow files directly in your repository. |
| ⚙️ Centralized Configuration | Repository settings, documentation options, and AI configuration are managed from a single configuration node. |
| ⏰ Scheduled Execution | Runs automatically on a configurable schedule without manual intervention. |
| 🚨 Error Workflow Support | Integrates with a dedicated error workflow to handle failures and operational alerts. |
